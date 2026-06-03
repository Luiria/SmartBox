import mysql from "mysql2/promise";
import { env } from "./env.js";

export const db = mysql.createPool({
    host: env.DB_HOST,
    user: env.DB_USER,
    password: env.DB_PASSWORD,
    database: env.DB_NAME,
    waitForConnections: true,
    connectionLimit: 10,
    queueLimit: 0
});


export async function testConnection(retries = 30, delay = 2000) {

    for (let i = 0; i < retries; i++) {
        try {
            const conn = await db.getConnection();
            conn.release();

            console.log("[DB] Connection successful");
            return;
        } catch (err) {

            if (i === retries - 1) {
                console.error("[DB] Connection failed permanently", err);
                process.exit(1);
            }

            await new Promise((r) => setTimeout(r, delay));

        }
    }

}

export default db;