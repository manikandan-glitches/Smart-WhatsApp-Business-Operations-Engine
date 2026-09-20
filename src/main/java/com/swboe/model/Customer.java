package com.swboe.model;

import jakarta.persistence.*;
import lombok.*;
import org.hibernate.annotations.CreationTimestamp;
import java.time.LocalDateTime;

@Entity
@Table(name = "customers")
@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class Customer {
    @Id
    @Column(length = 50)
    private String phone; // Primary Key string

    private String name;

    @Column(nullable = false, length = 28)
    @Builder.Default
    private String mode = "BOT"; // BOT, HUMAN

    @Column(nullable = false)
    @Builder.Default
    private Boolean muted = false;

    @CreationTimestamp
    @Column(name = "created_at", updatable = false)
    private LocalDateTime createdAt;
}