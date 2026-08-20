// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "AshenLivingJournalToneModulatorAdapter.generated.h"

/**
 * UAshenLivingJournalToneModulatorAdapter
 * 
 * Modulates living journal visual style based on journal tone tokens:
 * - Journal.Tone.SelfAccusatory -> Dark ink blots & jagged margins
 * - Journal.Tone.Harmonious -> Clean calligraphy & gold border
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingJournalToneModulatorAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenLivingJournalToneModulatorAdapter();

	/** Applies tone token to journal shader properties */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Journal")
	void ApplyJournalTone(const FGameplayTag& ToneTag);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Journal")
	float GetInkStainScalar() const { return CurrentInkStainScalar; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	FGameplayTag ActiveToneTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	float CurrentInkStainScalar = 0.0f;
};
