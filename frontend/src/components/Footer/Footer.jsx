import styles from "./Footer.module.css";

export default function Footer() {
  return (
    <footer className={styles.footer}>
      <div className={styles.footer_container}>
        <p>SmartBox © 2026</p>
        <caption>IoT Notification System</caption>
      </div>
    </footer>
  );
}
