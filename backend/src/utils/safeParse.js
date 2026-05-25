export default function safeParse(value) {

    if (value !== "string") return value;

    try {
        return JSON.parse(value);
    } catch {
        return value;
    }
}