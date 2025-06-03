import fs from "node:fs";
import path from "node:path";
import { dirname } from "path";
import { fileURLToPath } from "node:url";
import Busboy from "@fastify/busboy";
import UserModel from "../../models/userModel/userModel.js";
import UserPostModel from "../../models/userPostModel/userPostModel.js";

// Get the current directory name
const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

// Path for file save location
const imagesDir = path.join(__dirname, "../../../static/userUploads/images");
const videosDir = path.join(__dirname, "../../../static/userUploads/videos");

// Ensure the directory exists
if (!fs.existsSync(imagesDir) || !fs.existsSync(videosDir)) {
  fs.mkdirSync(imagesDir, { recursive: true });
  fs.mkdirSync(videosDir, { recursive: true });
}

export const addPostController = async (request, reply) => {
  try {
    // Get user email from request (Middleware)
    const userEmail = request.email;
    if (!userEmail) {
      return reply.code(401).send({ message: "Unauthorized" });
    }

    // Get MongoDB instance
    const fastify = request.server;

    // Find userId from email
    const userCollection = UserModel(fastify);
    const user = await userCollection.findOne({ email: userEmail });
    if (!user) {
      return reply.code(404).send({ message: "User not found" });
    }

    // Initialize Busboy
    const busboy = new Busboy({ headers: request.headers });

    let fileUploaded = false;
    let fieldsProcessed = false;
    let postData = {};

    // parsed input fields and saved
    busboy.on("field", (fieldname, val) => {
      postData[fieldname] = val;
      fieldsProcessed = true;
    });

    // on file upload
    busboy.on("file", (fieldname, file, filename, encoding, mimetype) => {
      if (!postData.title || !postData.content) {
        return reply.code(400).send({
          message: "Title and content are required before file upload",
        });
      }

      // Generate a random file name using Math.random and save the file
      const randomName = `${Math.random()
        .toString(36)
        .substring(2, 15)}-${Date.now()}`;
      const fileExtension = path.extname(filename).toLowerCase();

      let saveDir;
      if (mimetype.startsWith("image/")) {
        saveDir = imagesDir;
      } else if (mimetype.startsWith("video/")) {
        saveDir = videosDir;
      } else {
        return reply.code(400).send({
          message: "Invalid file type. Only images and videos are allowed.",
        });
      }

      const saveName = `${randomName}${fileExtension}`;
      const savePath = path.join(saveDir, saveName);

      const writeStream = fs.createWriteStream(savePath);
      file.pipe(writeStream);

      file.on("end", () => {
        fileUploaded = true;
        postData.filePath = savePath;
      });
    });

    // on complete
    busboy.on("finish", async () => {
      if (!postData.title || !postData.content) {
        return reply
          .code(400)
          .send({ message: "Title and content are required" });
      }

      if (fileUploaded && fieldsProcessed) {
        try {
          const userPostCollection = UserPostModel(fastify);
          const result = await userPostCollection.insertOne({
            userId: user._id,
            post: postData,
            createdAt: new Date(),
          });

          if (!reply.sent) {
            reply.send({
              message: "Post created successfully!",
              response: result,
            });
          }
        } catch (error) {
          if (!reply.sent) {
            console.error("Error saving post:", error);
            reply.code(500).send({ message: "Failed to save post" });
          }
        }
      } else {
        if (!reply.sent) {
          reply.code(400).send({ message: "No file or fields processed" });
        }
      }
    });

    // if any error
    busboy.on("error", (error) => {
      if (!reply.sent) {
        console.error("Error in Busboy:", error);
        reply.code(400).send({ message: "Error processing file data" });
      }
    });

    // Pipe the raw request stream into Busboy
    request.raw.pipe(busboy);
  } catch (error) {
    if (!reply.sent) {
      console.error("Error in controller:", error);
      return reply.code(500).send({ message: "Internal Server Error" });
    }
  }
};
