// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Memory/AshenMemoryPalaceGraphTypes.h"
#include "AshenMemoryPalaceCompanionAdapter.generated.h"

/**
 * UAshenMemoryPalaceCompanionAdapter
 * Modulates companion trust and triggers emotional reactions when exploring Mindscape loci tied to companion histories.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryPalaceCompanionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryPalaceCompanionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float EvaluateCompanionTrustBoostOnLocusUnsealed(FName CompanionID, EMemoryNodeType NodeType);
};
