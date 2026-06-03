import safeParse from "../../utils/safeParse.js";

export function mapAdafruitToEvent(item) {

    const value = safeParse(item.value);

    return {
        id: item.id,
        email: value.email,
        message: value.message,
        createdAt: item.created_at,
    };
}