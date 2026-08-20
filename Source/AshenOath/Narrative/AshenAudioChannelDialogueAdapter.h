// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenAudioChannelDialogueAdapter.generated.h"

/**
 * UAshenAudioChannelDialogueAdapter
 * Routes narrative and combat dialogue barks dynamically across World, Controller Speaker, and Intimate channels.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAudioChannelDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAudioChannelDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerChannelDialogue(FName SpeakerID, const FString& Line, EAudioConsciousnessChannel Channel);
};
