export const createPostSchema = {
  body: {
    type: "object",
    required: ["userId", "title", "description", "post"],
    properties: {
      title: {
        type: "string",
      },
      description: {
        type: "string",
      },
      userId: {
        type: "string",
      }
    },
  },
};
