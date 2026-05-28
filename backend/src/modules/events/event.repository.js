
export default class EventRepository {

    constructor(db) {
        this.db = db;
    }

    async findEvent(id) {

        const [rows] = await this.db.execute(
            `SELECT * FROM events WHERE external_id = ?`, [id]
        );

        return rows[0] || null;
    }

    async saveEvent(event) {

        const [result] = await this.db.execute(
            `INSERT INTO events (external_id, email, message, created_at)
             VALUES (?, ?, ?, ?)`
            , [
                event.id,
                event.email,
                event.message,
                event.createdAt
            ]
        );

        return true;
    }

    async getAndMarkNextEvent() {

        const connection = await this.db.getConnection();

        try {

            await connection.beginTransaction();

            const [rows] = await connection.execute(
                `
                SELECT *
                FROM events
                WHERE sent = FALSE
                ORDER BY created_at DESC
                LIMIT 1
                FOR UPDATE
                `
            );

            const event = rows[0];

            if (!event) {
                await connection.commit();
                return null;
            }

            await connection.execute(
                `
                UPDATE events
                SET sent = TRUE
                WHERE id = ?
                `,
                [event.id]
            );

            await connection.commit();
            return event;

        } catch (error) {
            await connection.rollback();
            throw error;

        } finally {
            connection.release();
        }
    }

    async getAllEvents() {

        const [rows] = await this.db.execute(
            `SELECT * FROM events;`
        );

        return rows || null;
    }

}