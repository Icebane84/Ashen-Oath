// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryProvenanceEvidencePackComponent.generated.h"

/**
 * UAshenMemoryProvenanceEvidencePackComponent
 * Memory component formatting narrative provenance, dialogue thread references, and combat whisper counts for integrated memory constellation nodes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryProvenanceEvidencePackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMemoryProvenanceEvidencePackComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	int32 DialogueThreadReferences = 18;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	int32 CombatWhispersGenerated = 5;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	FText FormatMemoryProvenanceEvidencePack(FName MemoryImprintID);
};
