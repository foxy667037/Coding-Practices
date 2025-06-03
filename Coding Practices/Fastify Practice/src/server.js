import pino from "pino";
import Fastify from "fastify";
import fastifyJwt from "@fastify/jwt";
import fastifyBcrypt from "fastify-bcrypt";
import fastifyMultipart from "@fastify/multipart";
import userRoutes from "./plugins/userPlugin/userPlugin.js";
import connectToMongo from "./databases/mongodb/mongodbConfig.js";
import userPostRoutes from "./plugins/userPostPlugin/userPostPlugin.js";

// Fastify instance
const fastifyInstance = Fastify({
  logger: {
    transport: {
      target: "pino-pretty",
      options: {
        colorize: true, 
        translateTime: "yyyy-mm-dd HH:MM:ss",
        ignore: "pid,hostname", 
      },
    },
  },
});

// start server
const startServer = async () => {
  try {
    // connect to mongodb
    const MongoURl = process.env.MONGO_DB_URL;
    await connectToMongo(MongoURl, fastifyInstance);

    // register hash password plugin
    const saltCounts = 12;
    fastifyInstance.register(fastifyBcrypt, {
      saltWorkFactor: saltCounts,
    });

    // register jwt plugin
    const jwtSecret = process.env.JWT_SECRET;
    fastifyInstance.register(fastifyJwt, {
      secret: `${jwtSecret}`,
    });

    // register fastify multipart
    fastifyInstance.register(fastifyMultipart, {
      limits: {
        fieldNameSize: 100, // Keep field name size small (reasonable)
        fieldSize: 10000, // Allow text fields up to 10KB
        fields: 5, // Allow at least 5 non-file fields
        fileSize: 10 * 1024 * 1024, // Allow files up to 10MB
        files: 2, // Allow up to 2 file fields
        headerPairs: 2000, // Keep this high for large headers
        parts: 10, // Allow at least 10 parts (fields + files)
      },
    });

    // Default Route
    fastifyInstance.get("/", async (request, reply) => {
      return { message: "Server Running!!" };
    });

    // Register User Routes
    fastifyInstance.register(userRoutes);

    // Register User Post Routes
    fastifyInstance.register(userPostRoutes);

    const PORT = process.env.PORT || 4000;
    await fastifyInstance.listen({ port: PORT });

    console.log(`Server is listening on ${PORT}`);
  } catch (err) {
    fastifyInstance.log.error(err);
    process.exit(1);
  }
};

startServer();