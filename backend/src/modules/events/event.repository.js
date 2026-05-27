
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

}