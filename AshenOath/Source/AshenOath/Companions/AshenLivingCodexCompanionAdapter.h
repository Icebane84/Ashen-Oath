// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenLivingCodexCompanionAdapter.generated.h"

/**
 * UAshenLivingCodexCompanionAdapter
 * Manages companion trust gains (+0.08) and custom voice commentary when unsealing companion-specific backstory codex entries.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingCodexCompanionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingCodexCompanionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float EvaluateCompanionTrustGain(FName EntryID, FName CompanionID);
};
