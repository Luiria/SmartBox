import styles from "./Notification.module.css";

const max = 40;

export default function Notification({ notifications }) {
  if (!notifications || notifications.length === 0) return null;

  return (
    <div className={styles.notification_container}>
      <ul>
        
        {notifications.map((event) => {
          
          const date = new Date(event.created_at).toLocaleString("fr-FR", {
            dateStyle: "medium",
            timeStyle: "short",
          });

          return (
            <li key={event.id} className={styles.notification}>
              <p className={styles.message}>
                {event.message.slice(0, max) + "..."}
              </p>
              <p className={styles.date}>{date}</p>
            </li>
          );

        })}

      </ul>
    </div>
  );
}
