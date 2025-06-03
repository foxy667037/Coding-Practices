const verifyJwt = async (request, reply) => {
  try {
    // Get token from headers
    const authHeader = request.headers["authorization"];
    if (!authHeader) {
      return reply.code(401).send({ message: "Token not found" });
    }

    // Check if token format is "Bearer <token>"
    const tokenParts = authHeader.split(" ");
    if (tokenParts.length !== 2 || tokenParts[0] !== "Bearer") {
      return reply.code(401).send({ message: "Invalid token format" });
    }

    // Extract the token
    const token = tokenParts[1];

    // Verify JWT token
    const decodedUser = await request.jwtVerify(token);

    // Attach the user email to the request object
    request.email = decodedUser.payload.email;
  } catch (err) {
    return reply
      .code(401)
      .send({ message: "Invalid or expired token", error: err.message });
  }
};

const fetchUser = async (request, reply, done) => {
  verifyJwt(request, reply)
    .then(() => {
      done();
    })
    .catch((err) => {
      reply
        .code(401)
        .send({ message: "Invalid or expired token", error: err.message });
    });
};

export default fetchUser;
