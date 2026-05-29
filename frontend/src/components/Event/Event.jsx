import styles from "./Event.module.css";

export default function Event({ event }) {
  return (
    <article className={styles.event} key={event.id}>
      <p className={styles.email}>{event.email}</p>
      <p className={styles.message}>{event.message}</p>
      <p className={styles.date}>{event.created_at}</p>
    </article>
  );
}
