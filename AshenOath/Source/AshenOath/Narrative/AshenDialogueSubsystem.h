// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenDialogueSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDialogueLineTriggeredSignature, FName, SpeakerID, FString, DialogueText);

/**
 * UAshenDialogueSubsystem
 *
 * World Subsystem handling branching narrative dialogue, bark muting during peak resonance, and speaker focus.
 */
UCLASS()
class ASHENOATH_API UAshenDialogueSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Dialogue")
	bool TriggerDialogueLine(FName SpeakerID, FString DialogueText, bool bIsBark = false);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Dialogue")
	void SetBarksMuted(bool bMute) { bBarksMuted = bMute; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Dialogue|Events")
	FOnDialogueLineTriggeredSignature OnDialogueLineTriggered;

private:
	bool bBarksMuted = false;
};
