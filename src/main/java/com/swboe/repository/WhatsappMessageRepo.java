package com.swboe.repository;

import com.swboe.model.WhatsappMessage;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import java.util.List;

@Repository
public interface WhatsappMessageRepo extends JpaRepository<WhatsappMessage, Integer> {
    List<WhatsappMessage> findByContactPhoneOrderByCreatedAtAsc(String contactPhone);
}
