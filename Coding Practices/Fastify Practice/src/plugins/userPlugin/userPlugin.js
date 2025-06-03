import {
  findUserController,
  loginUserController,
  deleteUserController,
  createUserController,
  updateUserController,
  showAllUsersController,
  getUserDetailsController,
  getLoggedInUserDetailsController,
} from "../../controllers/userController/userController.js";
import fetchUser from "../../hooks/fetchUserHook/fetchUserHook.js";
import {
  loginUserSchema,
  createUserSchema,
} from "../../schemas/userSchema/userSchema.js";

const userRoutes = async (fastify, options) => {
  // create user route
  fastify.post(
    "/api/create_user",
    { schema: createUserSchema },
    createUserController
  );

  // login user route
  fastify.post(
    "/api/login_user",
    { schema: loginUserSchema },
    loginUserController
  );

  // get all user route
  fastify.get("/api/all_users", showAllUsersController);

  // get only one user
  fastify.get("/api/find_user", findUserController);

  // get finded using details
  fastify.get("/api/get_user_details/:id", getUserDetailsController);

  // get logged in user details
  fastify.get(
    "/api/logged_in_user_details",
    { preHandler: fetchUser },
    getLoggedInUserDetailsController
  );

  // delete the user
  fastify.delete(
    "/api/delete_user",
    { preHandler: fetchUser },
    deleteUserController
  );

  // update the user
  fastify.put(
    "/api/update_user_details",
    {preHandler: fetchUser},
    updateUserController
  )
};

export default userRoutes;
