import UserModel from "../../models/userModel/userModel.js";

// create user controller
export const createUserController = async (request, reply) => {
  try {
    const { name, email, password } = request.body;

    // verify email
    if (!email || !/\S+@\S+\.\S+/.test(email)) {
      return reply.code(400).send({ message: "Invalid email format" });
    }

    const fastify = request.server;

    // Get the MongoDB collection
    const userCollections = UserModel(fastify);

    // hash the passsword
    const hashedPassword = await fastify.bcrypt.hash(password);

    // Insert user into MongoDB
    const result = await userCollections.insertOne({
      name: name,
      email: email,
      password: hashedPassword,
      createdAt: new Date(),
    });

    // send response
    return reply.code(201).send({
      response: {
        message: "User Created.",
        data: {
          id: result.insertedId,
          name: name,
          email: email,
        },
      },
    });
  } catch (error) {
    request.log.error(error);
    return reply.code(500).send({ message: "Internal Server Error" });
  }
};

// login user controller
export const loginUserController = async (request, reply) => {
  try {
    const { email, password } = request.body;

    // verify email
    if (!email || !/\S+@\S+\.\S+/.test(email)) {
      return reply.code(400).send({ message: "Invalid email format" });
    }

    const fastify = request.server;

    // Get the MongoDB collection
    const userCollections = UserModel(fastify);

    // find user using email
    const resultedUser = await userCollections.findOne({ email: email });
    if (!resultedUser) {
      return reply.code(404).send({ message: "User not found!" });
    }

    // validate password
    const validatePassword = await fastify.bcrypt.compare(
      password,
      resultedUser.password
    );
    if (!validatePassword) {
      return reply.code(401).send({ message: "Invalid Credentials" });
    }

    // Assign jwt token for later verification
    const payload = {
      email: email,
    };
    const jwtToken = fastify.jwt.sign({ payload });

    // send response
    return reply.code(201).send({
      response: {
        message: "Login Successfully.",
        data: {
          email: email,
          jwttoken: jwtToken,
        },
      },
    });
  } catch (err) {
    request.log.error(error);
    return reply.code(500).send({ message: "Internal Server Error" });
  }
};

// show all user controller
export const showAllUsersController = async (request, reply) => {
  try {
    // Get the MongoDB collection
    const fastify = request.server;
    const userCollections = UserModel(fastify);

    // get all users from MongoDB
    const resultedUsers = await userCollections
      .find({}, { projection: { password: 0 } })
      .toArray();
    return reply.code(201).send({
      response: {
        message: "All Users.",
        data: {
          list: resultedUsers,
        },
      },
    });
  } catch (error) {
    request.log.error(error);
    return reply.code(500).send({ message: "Internal Server Error" });
  }
};

// find user controller
export const findUserController = async (request, reply) => {
  try {
    // Get the searched name from url query
    const { name } = request.query;

    // Get the MongoDB collection
    const fastify = request.server;
    const userCollections = UserModel(fastify);

    let query = {};

    if (query) {
      query = {
        name: { $regex: name, $options: "i" }, // i for case-insensitive
      };
    }

    // Get users from MongoDB
    const resultedUsers = await userCollections
      .find({ name }, { projection: { password: 0 } })
      .toArray();
    return reply.code(201).send({
      response: {
        message: "Searched User.",
        data: {
          list: resultedUsers,
        },
      },
    });
  } catch (error) {
    request.log.error(error);
    return reply.code(500).send({ message: "Internal Server Error" });
  }
};

// get user's controller
export const getUserDetailsController = async (request, reply) => {
  try {
    // Get the MongoDB collection
    const fastify = request.server;
    const userCollections = UserModel(fastify);

    // Get the userId from url
    const userId = new fastify.mongo.ObjectId(request.params.id);

    // Get user details from MongoDB
    const resultedUsers = await userCollections.findOne(
      { _id: userId },
      { projection: { password: 0 } }
    );
    return reply.code(201).send({
      response: {
        message: "Resulted User Details.",
        data: {
          list: resultedUsers,
        },
      },
    });
  } catch (error) {
    request.log.error(error);
    return reply.code(500).send({ message: "Internal Server Error" });
  }
};

// get logged-in user controller
export const getLoggedInUserDetailsController = async (request, reply) => {
  try {
    // Get the MongoDB collection
    const fastify = request.server;
    const userCollections = UserModel(fastify);

    // Get the userEmail
    const userEmail = request.email;

    // Get user details from MongoDB
    const resultedUsers = await userCollections.findOne(
      { email: userEmail },
      { projection: { password: 0 } }
    );
    return reply.code(201).send({
      response: {
        message: "Logged-In User Details.",
        data: {
          list: resultedUsers,
        },
      },
    });
  } catch (error) {
    request.log.error(error);
    return reply.code(500).send({ message: "Internal Server Error" });
  }
};

// delete user controller
export const deleteUserController = async (request, reply) => {
  try {
    const userEmail = request.email;
    if (!userEmail) {
      return reply.code(404).send({ message: "Email Not Found" });
    }

    // Get the MongoDB collection
    const fastify = request.server;
    const userCollections = UserModel(fastify);

    // delete the user
    const resultedDeletedUser = await userCollections.deleteOne({
      email: userEmail,
    });

    // Check if user was deleted
    if (resultedDeletedUser.deletedCount === 0) {
      return reply.code(404).send({ message: "User Already Deleted." });
    }

    return reply.code(200).send({ message: "User Deleted Successfully." });
  } catch (error) {
    request.log.error(error);
    return reply.code(500).send({ message: "Internal Server Error" });
  }
};

// update user details controller
export const updateUserController = async (request, reply) => {
  try {
    const userEmail = request.email;
    if (!userEmail) {
      return reply.code(404).send({ message: "Email Not Found" });
    }

    // Get the MongoDB collection
    const fastify = request.server;
    const userCollections = UserModel(fastify);

    // Find the existing user
    const existingUser = await userCollections.findOne({ email: userEmail });

    if (!existingUser) {
      return reply.code(404).send({ message: "User Not Found." });
    }

    // Extract fields from request body
    const { name, email, password } = request.body;

    // Build update object dynamically
    let updateFields = {};
    if (name) updateFields.name = name;
    if (email) updateFields.email = email;
    if (password) {
      // hash the passsword
      const hashedPassword = await fastify.bcrypt.hash(password);
      updateFields.password = hashedPassword;
    }

    // return error if no fields update
    if (Object.keys(updateFields).length === 0) {
      return reply.code(400).send({ message: "No fields to update" });
    }

    // if fields not empty then perform the update
    const updateResult = await userCollections.updateOne(
      { email: userEmail },
      { $set: updateFields }
    );

    if (updateResult.modifiedCount === 0) {
      return reply
        .code(400)
        .send({ message: "Update failed. No changes made." });
    }

    return reply.code(200).send({ message: "User updated successfully." });
  } catch (error) {
    request.log.error(error);
    return reply.code(500).send({ message: "Internal Server Error" });
  }
};
