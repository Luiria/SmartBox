import styles from "./Event.module.css";

export default function Event({ event }) {

  const date = new Date(event.created_at).toLocaleString("fr-FR", {
    dateStyle: "medium",
    timeStyle: "short",
  });

  return (
    <article className={styles.event} key={event.id}>
      <p className={styles.email}>{event.email}</p>
      <p className={styles.message}>{event.message}</p>
      <p className={styles.date}>{date}</p>
    </article>
  );
}
