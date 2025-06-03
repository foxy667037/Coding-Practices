import { addPostController } from "../../controllers/userPostController/userPostController.js";
import fetchUser from "../../hooks/fetchUserHook/fetchUserHook.js";
import { createPostSchema } from "../../schemas/userPostSchema/userPostSchema.js";

const userPostRoutes = async (fastify, options) => {
  fastify.post(
    "/api/add_post",
    {
      preHandler: fetchUser,
    },
    addPostController
  );
};

export default userPostRoutes;
