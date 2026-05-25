import dotenv from "dotenv";

dotenv.config();

export const env = {
    ADAFRUIT_USERNAME: process.env.ADAFRUIT_USERNAME,
    ADAFRUIT_KEY: process.env.ADAFRUIT_KEY,
    ADAFRUIT_FEED: process.env.ADAFRUIT_FEED,
    PORT: process.env.PORT,
};