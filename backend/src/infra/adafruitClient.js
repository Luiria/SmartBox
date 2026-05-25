import axios from "axios";
import { env } from "../config/env.js";

export default class AdafruitClient {
    constructor() {
        this.url = `https://io.adafruit.com/api/v2/${env.ADAFRUIT_USERNAME}/feeds/${env.ADAFRUIT_FEED}/data`;
        this.key = env.ADAFRUIT_KEY;
    }

    async getLatest() {
        try {
            const res = await axios({
                method: "get",
                url: this.url,
                headers: {
                    "X-AIO-Key": this.key,
                },
                params: {
                    limit: 1,
                }
            });

            return res.data[0];

        } catch (error) {

            console.error("[AdafruitClient] API error:", {
                message: error.message,
                code: error.code,
                response: error.response?.data,
            });

            throw new Error("ADAFRUIT_API_FAILED");
        }
    }
}
