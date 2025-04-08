-- Enable foreign key constraints
PRAGMA foreign_keys = ON;

-- Step 1: Verify or Create Tables

-- Users Table
CREATE TABLE IF NOT EXISTS Users (
    user_id INTEGER PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    email VARCHAR(100) NOT NULL UNIQUE,
    password_hash VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- BoardCollaborators Table
CREATE TABLE IF NOT EXISTS BoardCollaborators (
    board_id INTEGER,
    collaborator_id INTEGER,
    added_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (board_id, collaborator_id),
    FOREIGN KEY (board_id) REFERENCES Boards(board_id) ON DELETE CASCADE,
    FOREIGN KEY (collaborator_id) REFERENCES Users(user_id) ON DELETE CASCADE
);

-- Boards Table
CREATE TABLE IF NOT EXISTS Boards (
    board_id INTEGER PRIMARY KEY,
    user_id INTEGER,
    name VARCHAR(100) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);

-- Lists Table
CREATE TABLE IF NOT EXISTS Lists (
    list_id INTEGER PRIMARY KEY,
    board_id INTEGER,
    name VARCHAR(100) NOT NULL,
    position INT DEFAULT 0,
    FOREIGN KEY (board_id) REFERENCES Boards(board_id)
);

-- Tasks Table
CREATE TABLE IF NOT EXISTS Tasks (
    task_id INTEGER PRIMARY KEY,
    list_id INTEGER,
    title VARCHAR(255) NOT NULL,
    description TEXT,
    due_date DATE,
    position INT DEFAULT 0,
    completed BOOLEAN DEFAULT FALSE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (list_id) REFERENCES Lists(list_id)
);

-- Comments Table
CREATE TABLE IF NOT EXISTS Comments (
    comment_id INTEGER PRIMARY KEY,
    task_id INTEGER,
    user_id INTEGER,
    content TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (task_id) REFERENCES Tasks(task_id),
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);

-- Attachments Table
CREATE TABLE IF NOT EXISTS Attachments (
    attachment_id INTEGER PRIMARY KEY,
    task_id INTEGER,
    filename VARCHAR(255) NOT NULL,
    file_path VARCHAR(255) NOT NULL,
    uploaded_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (task_id) REFERENCES Tasks(task_id)
);

-- Notifications Table
CREATE TABLE IF NOT EXISTS Notifications (
    notification_id INTEGER PRIMARY KEY,
    user_id INTEGER NOT NULL, -- The user receiving the notification
    type VARCHAR(50) NOT NULL, -- Type of notification (e.g., 'task_due', 'new_comment', 'added_to_board')
    related_id INTEGER, -- ID of the related entity (e.g., task_id, board_id, or list_id)
    message TEXT NOT NULL, -- The notification message
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- Timestamp of notification creation
    read BOOLEAN DEFAULT FALSE, -- Whether the notification has been read
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);

-- Templates Table
CREATE TABLE IF NOT EXISTS Templates (
    template_id INTEGER PRIMARY KEY,
    user_id INTEGER,  -- The user who created the template
    name VARCHAR(100) NOT NULL,  -- Name of the template
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,  -- When the template was created
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);

-- TemplateLists Table
CREATE TABLE IF NOT EXISTS TemplateLists (
    template_list_id INTEGER PRIMARY KEY,
    template_id INTEGER,  -- The template this list belongs to
    name VARCHAR(100) NOT NULL,  -- Name of the list
    position INT DEFAULT 0,  -- Position of the list in the template
    FOREIGN KEY (template_id) REFERENCES Templates(template_id)
);

-- Token Storage Table
CREATE TABLE IF NOT EXISTS TokenStorage (
    id INTEGER PRIMARY KEY,
    token VARCHAR(255) NOT NULL, -- Store the token here
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);