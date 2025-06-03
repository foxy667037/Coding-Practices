const UserModel = (fastify) => {
  return fastify.mongo.db.collection("users");
};

export default UserModel;