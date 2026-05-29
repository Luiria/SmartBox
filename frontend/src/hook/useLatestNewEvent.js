import { useEffect, useState } from "react";
import { fetchLatestNewsEvent } from "../api/event.api";

export function useLatestNewEvent() {

    const [notifications, setNotifications] = useState([]);

    useEffect(() => {
        async function load() {

            try {
                const data = await fetchLatestNewsEvent();
                if(!data) return ;

                setNotifications(prev => {
                    //  check
                    // if (prev.find(n => n.id === data.id)) return prev;

                    return [...prev, data];
                });

                setTimeout(() => {
                    setNotifications(prev =>
                        prev.filter(n => n.id != data.id)
                    );
                }, 10000)


            } catch (err) {
                console.error("[useLatestNewEvent]", err);
            }
        }
        load();

        const interval = setInterval(load, 5000);
        return () => clearInterval(interval);
    }, []);

    return { notifications };
}