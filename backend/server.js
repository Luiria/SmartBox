import { env } from "./src/config/env.js";
import { testConnection } from "./src/config/db.js";
import app from "./app.js";

await testConnection();

const PORT = env.PORT || 3000;

app.listen(PORT, () => {
    console.log(`Serveur démarré sur le port ${PORT}...`);
});