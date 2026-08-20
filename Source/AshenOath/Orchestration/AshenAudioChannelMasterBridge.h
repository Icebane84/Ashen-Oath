// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenAudioChannelMasterBridge.generated.h"

/**
 * UAshenAudioChannelMasterBridge
 * Master domain bridge dispatching posture break opportunities to the DualSense speaker controller and accessibility subtitles.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAudioChannelMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAudioChannelMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bAudioBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastTacticalCue(FName SpeakerID, const FString& Line, float ActionWindowSeconds);
};
