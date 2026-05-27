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

export async function testConnection() {
    try {
        const conn = await db.getConnection();
        conn.release();
        console.log("[DB] Connection successful");
    } catch (error) {
        console.error("[DB] Connection failed", error);
        process.exit(1);
    }
}

export default db;