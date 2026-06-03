INSERT INTO events (
        external_id,
        email,
        message,
        created_at,
        sent
    )
VALUES (
        'evt_001',
        'john.doe@example.com',
        'The mailbox door has been opened. Please check whether you have received any mail.',
        '2026-06-02T08:15:00Z',
        FALSE
    ),
    (
        'evt_002',
        'alice.smith@example.com',
        'New mail has been detected in the mailbox.',
        '2026-06-02T09:30:00Z',
        FALSE
    ),
    (
        'evt_003',
        'bob.wilson@example.com',
        'The mailbox door has been opened. Please check whether you have received any mail.',
        '2026-06-02T10:45:00Z',
        TRUE
    ),
    (
        'evt_004',
        'charlie.brown@example.com',
        'New mail has been detected in the mailbox.',
        '2026-06-02T11:20:00Z',
        FALSE
    ),
    (
        'evt_005',
        'emma.jones@example.com',
        'The mailbox door has been opened. Please check whether you have received any mail.',
        '2026-06-02T12:10:00Z',
        TRUE
    );