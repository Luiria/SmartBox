import safeParse from "../../utils/safeParse.js";

export default class EventService {

    constructor(client) {
        this.client = client;
    }

    async getLatestEvent() {
        const item = await this.client.getLatest();

        return {
            id: item.id,
            createdAt: item.created_at,
            value: safeParse(item.value)
        }
    }

}
