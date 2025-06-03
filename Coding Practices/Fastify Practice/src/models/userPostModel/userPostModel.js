const UserPostModel = (fastify) => {
    return fastify.mongo.db.collection("posts");
  };
  
  export default UserPostModel;