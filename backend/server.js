import { env } from "./src/config/env.js";
import app from "./app.js";

const PORT = env.PORT || 3000;

app.listen(PORT, () => {
    console.log(`Serveur démarré sur le port ${PORT}...`);
});