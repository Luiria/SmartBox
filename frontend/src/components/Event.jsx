export default function Event({ event }) {
  return (
    <article className="event">
      <p>{event.id}</p>
      <strong>{event.email}</strong>
      <p>{event.message}</p>
      <small>{event.createdAt}</small>
    </article>
  );
}
