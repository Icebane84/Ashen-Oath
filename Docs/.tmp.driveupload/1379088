# **PHOENIX ARTIFACT: AOP-RIC-002**

## **SLM GOVERNANCE PROTOCOL & JSON SCHEMA**

**Purpose:** To define the strict data contract between the offline Reflective Identity Compiler (SLM) and the Unreal Engine C++ Governance Layer. This protocol ensures zero-hallucination processing and protects the deterministic integrity of the FSoulStateVector.

### **PART I: THE JSON EVIDENCE PACK SCHEMA**

When the SLM completes its offline compilation during the Heartstone Integration Ritual, it must return a single JSON object. It is strictly forbidden from returning conversational text.

The JSON must adhere to this exact structure:

{  
  "compilation\_id": "req\_0045\_heartstone\_rest",  
  "observation\_summary": "Kaelen's failure to protect a civilian at Oakhaven resulted in catastrophic consequences, validating his deepest fears of inadequacy.",  
  "confidence\_score": 0.94,  
  "supporting\_memories": \[  
    "mem\_oakhaven\_failure\_012",  
    "mem\_garrett\_warning\_005"  
  \],  
  "proposed\_deltas": {  
    "Resolve": \-0.05,  
    "Corruption": 0.12,  
    "Isolation": 0.08,  
    "GarrettTrust": \-0.04  
  }  
}

#### **Schema Constraints:**

* confidence\_score: Must be a float between ![][image1] and ![][image2]. If ![][image3], the C++ layer automatically rejects the payload to prevent uncertain identity shifts.  
* supporting\_memories: An array of FName strings. These **must** perfectly match the IDs of FPsychologicalImprint structs currently residing in the UAshenOath\_ImprintBufferComponent.  
* proposed\_deltas: Key-value pairs targeting the exact float variables within the FSoulStateVector.

### **PART II: THE C++ DESERIALIZATION STRUCTS**

To safely ingest this JSON into Unreal Engine without manual string parsing, we use FJsonObjectConverter mapped to strongly-typed USTRUCTs.

// AshenSLMTypes.h

USTRUCT()  
struct FAshenSLMDeltas  
{  
    GENERATED\_BODY()

    UPROPERTY() float Resolve \= 0.0f;  
    UPROPERTY() float Corruption \= 0.0f;  
    UPROPERTY() float Shame \= 0.0f;  
    UPROPERTY() float Grace \= 0.0f;  
    UPROPERTY() float Isolation \= 0.0f;  
    UPROPERTY() float GarrettTrust \= 0.0f;  
    UPROPERTY() float SerafinaTrust \= 0.0f;  
};

USTRUCT()  
struct FAshenSLMEvidencePack  
{  
    GENERATED\_BODY()

    UPROPERTY() FString compilation\_id;  
    UPROPERTY() FString observation\_summary;  
    UPROPERTY() float confidence\_score \= 0.0f;  
    UPROPERTY() TArray\<FName\> supporting\_memories;  
    UPROPERTY() FAshenSLMDeltas proposed\_deltas;  
};

### **PART III: THE GOVERNANCE VALIDATION LAYER (C++)**

This logic resides within UAshenSerafinaIdentityCompilerSubsystem::ProcessSLMPayload(). It acts as the firewall between the AI and the game engine.

// AshenSerafinaIdentityCompilerSubsystem.cpp

void UAshenSerafinaIdentityCompilerSubsystem::ProcessSLMPayload(const FString& JsonPayload)  
{  
    FAshenSLMEvidencePack EvidencePack;

    // 1\. JSON PARSING & SCHEMA VALIDATION  
    if (\!FJsonObjectConverter::JsonObjectStringToUStruct(JsonPayload, \&EvidencePack, 0, 0))  
    {  
        UE\_LOG(LogAshenRIC, Error, TEXT("SLM Payload rejected: Invalid JSON Schema."));  
        return;  
    }

    // 2\. CONFIDENCE THRESHOLD CHECK  
    if (EvidencePack.confidence\_score \< 0.75f)  
    {  
        UE\_LOG(LogAshenRIC, Warning, TEXT("SLM Payload rejected: Confidence score (%f) too low."), EvidencePack.confidence\_score);  
        return;  
    }

    // 3\. PROVENANCE VALIDATION (Zero-Hallucination Check)  
    UAshenOath\_ImprintBufferComponent\* ImprintBuffer \= GetImprintBuffer();  
    for (const FName& MemID : EvidencePack.supporting\_memories)  
    {  
        if (\!ImprintBuffer-\>ContainsImprint(MemID))  
        {  
            // CRITICAL: The SLM invented a memory that the engine does not have a record of.  
            // Reject the entire payload to maintain deterministic integrity.  
            UE\_LOG(LogAshenRIC, Error, TEXT("SLM Hallucination Detected\! Memory ID \[%s\] does not exist. Payload rejected."), \*MemID.ToString());  
            return;  
        }  
    }

    // 4\. MATHEMATICAL DELTA CLAMPING (Universal Law II)  
    // Prevent the SLM from breaking the game balance with extreme values.  
    const float MaxDeltaPerCycle \= 0.15f; 

    FAshenSLMDeltas ClampedDeltas;  
    ClampedDeltas.Resolve \= FMath::Clamp(EvidencePack.proposed\_deltas.Resolve, \-MaxDeltaPerCycle, MaxDeltaPerCycle);  
    ClampedDeltas.Corruption \= FMath::Clamp(EvidencePack.proposed\_deltas.Corruption, \-MaxDeltaPerCycle, MaxDeltaPerCycle);  
    ClampedDeltas.Isolation \= FMath::Clamp(EvidencePack.proposed\_deltas.Isolation, \-MaxDeltaPerCycle, MaxDeltaPerCycle);  
    ClampedDeltas.GarrettTrust \= FMath::Clamp(EvidencePack.proposed\_deltas.GarrettTrust, \-MaxDeltaPerCycle, MaxDeltaPerCycle);  
    ClampedDeltas.SerafinaTrust \= FMath::Clamp(EvidencePack.proposed\_deltas.SerafinaTrust, \-MaxDeltaPerCycle, MaxDeltaPerCycle);

    // 5\. APPLICATION TO THE SOUL STATE VECTOR  
    USoulConstellationSubsystem\* Kernel \= GetWorld()-\>GetGameInstance()-\>GetSubsystem\<USoulConstellationSubsystem\>();  
    if (Kernel)  
    {  
        Kernel-\>ApplyIdentityDeltas(  
            ClampedDeltas.Resolve,  
            ClampedDeltas.Corruption,  
            ClampedDeltas.Isolation,  
            ClampedDeltas.GarrettTrust,  
            ClampedDeltas.SerafinaTrust  
        );

        // Consume the validated imprints from the buffer so they are not re-processed  
        ImprintBuffer-\>ConsumeMemories(EvidencePack.supporting\_memories);  
          
        UE\_LOG(LogAshenRIC, Log, TEXT("SLM Payload Accepted and Clamped. Identity Compiled."));  
    }  
}

### **CONCLUSION**

This implementation strictly enforces **Insight B (Provenance Validation)** and **Insight C (The Mechanical Weight of Entropy)**. By clamping the delta output, the C++ layer ensures Kaelen cannot radically shift his moral alignment in a single rest, forcing the player to deal with the slow, creeping weight of cumulative psychological changes.

[image1]: <data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABoAAAAZCAYAAAAv3j5gAAABzElEQVR4Xu2UQShEQRzG34aiRNIm9u17u6+N9ra1UUpOLnsgLSfrKkflopSTXBxdlKScRK425cDBQTntAeUkF6e9cUDh9999s41htLnRfvX1Zr7/N/9vdt/Mc5wG/gxc123zfX8GbsH1ZDI5YHpsSKVSHZ7nLYRrV2Cv6akgCIJOiidwNRqNticSiQzjazhlek2wIWx+iaA51rUyzjG+RR8yvQ6FJQyXPLuUxrwAb1jQo3sNNOPZhocyViLzNXody79Uc0pzCWE3uzURxOPxQfRHnhO6roO1AZ4H2aiuo+XhE3pWF9OwbAaJScyyO13XgWeM+psZxHwc/R0WdLHS0BZk6jpUQ1vQJ12JZsM6g+Td1heEkPttEPXFLw0dS5CtoU3X8W1Dm+6FJ8dsqILgsq7rwDNC/dUWBPM1US4owhk8kgunmeVEvchTaXKxOe59DCMy557E8NzBDeUR0GcerQzTui5NZ+E9hWQoRRivwgtpLkIsFutmXoLPcNjmy2azLQQdoO052iWuQIoEbVI8xTQZLr5inFGe8JcXvernxVd6+Pkq4t33qwdrB56zMVd5TERY1E+jaRqNSrhp+AFN8k5lrTxlbhoaaOAf4wPkjpVJr1PvawAAAABJRU5ErkJggg==>

[image2]: <data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABoAAAAZCAYAAAAv3j5gAAABdElEQVR4Xu2UvUvDQADFU1RQEB0kg+bjTMjSwSkgKI4uHQQpDoKzCC6CSycn8R9wFBEcRBRncXJycG1HJ4WCk5sOIlV/lzTpcTR+hCxKHvy4u9d39y7D1TBK/TlNx1rV/a8UBMGY67pbQogD2IFJPROJH6qwCdfQoehYz2TJ8zy2iCZF6+wbZl5jfoc/q2ejIkLLjPPQ/kXRIPlDuJDzxGS9R9mVbdsjSrYn+cnw8NMiDvPJPzI2VB+vDi/4oeqnylG0SP5dL2K9hP8Ba6qfKkdRdGBWke6nylHU6Hdg4UVkt/sdWHhR1oFZfqocRQvk3/QDkyKoq36q74p83x93HGeKaUWueScW+XvYV3Ps38B7gqrqp0qK4MToHpbIsqwJ/Ca8wlzXrjDfhVt5CWmEYThE0TneqaE84khu/B7a0BHxJ0ue2dDi1jMyY5rmKN6lG/+9iGSvLJA+2TPGGhzBDRezew3FaYALhLAiR7nWA6VK/WN9Ask2ePkVFKH3AAAAAElFTkSuQmCC>

[image3]: <data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADoAAAAZCAYAAABggz2wAAADD0lEQVR4Xu2WS2gTURiFE1pB8YWPGNommSQNBBFEjSh1p6ig4gOqWLQbcVERQVRQBBeCdNG6ENSFiCIuVLB1KQoWFVwoVlwVNyI+KLhqd4VufHyHzLS3fydponXlHDjM3HPP/ef+9zmxWIQIEf5b5HK5oud5vfAmPJRKpeZZjwW+JvgI7vTfpzCRSCyQL5PJHKC8yS/HW1tbV6B1ZrPZNSbkvwWdaIcf9GF1hvdL8Fk+n19svS7obAnfGPwVRuJ1YWvk+dDWwb6Z4teMZDI5v1QqzbG6C0Y3zUc/wsOBRgJLKA/CE67XAt9uPO+88ipw+RIOBInwfgsO4f/Gsx/uQm4w4eqHvwz74P1CoZCw9S6UIBzT7DhyHO2eOhwsvzAwU6dot9XVlJy+jb4q0ChfM/H/CnE+vJGgL+B1zZQ1hAHv1ZBElcRd9O/oeVd3Qf069vJSR1IfetDbHW3WEm0g0Bb4Cl5uaWlZZg3V4CdUKdFpejWk0+k9+G/Y7aKBR7/C8z0chq/hWtdTDQ10Zi8N3sALLNFF1jAT/INH+2laQvUmqgHG/xy22Tpi3CHe+Zi/Lyl34htli20w1klotGjUodGhwUkdONZTK9SWOANhCdWbqN+noebm5uW2rlgsLow5hw+DkvJn9gHFxkmnAyo3wy8EPlbLXTcTKiVUSQ+D+oHvKf7+WKWOO/DK9+xX+IlZTdr6CZhZPfsnyzYAMbrDEvITHdbou3oY8K2EI2pj69COUPdTExNoTqJik+uvhGCf6s6r+yASdIDQ9kfGuSaIORftsah3X9a3hKA8AXw7vPJPQLetI+451bmJOku36vUVhilXS62jJGhwaPsWXgw0lmJBHUHrCDTKR/1kpu0rfF2qU1KuLqC3qU/uSYz/INq4Z66hehBnza8mwBN4G+asIQzM6nq8n7UN4H7eB+lMj9u5TPkvaFweinGnuZI5XSnRWPnn44xXngQNlu7tEXhcddZcN5Qk7NXs2Low6ARmkLaT4L5afzYCqC1Jbqt2ViimYusbs/aPGyFChAgRItSO36e0429IXin9AAAAAElFTkSuQmCC>