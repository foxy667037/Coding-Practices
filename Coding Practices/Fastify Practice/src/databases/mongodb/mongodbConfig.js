import fastifyMongodb from "@fastify/mongodb";

const connectToMongo = async (MongoUrl, fastifyInstance) => {
  try {
    await fastifyInstance.register(fastifyMongodb, {
      forceClose: true,
      url: MongoUrl
    });
    console.log("Connected to MongoDB successfully.");
  } catch (err) {
    fastifyInstance.log.error(err);
    process.exit(1);
  }
};

export default connectToMongo;