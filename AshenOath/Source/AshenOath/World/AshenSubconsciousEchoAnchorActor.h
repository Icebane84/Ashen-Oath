// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "AshenSubconsciousEchoAnchorActor.generated.h"

class USphereComponent;
class UAudioComponent;

/**
 * AAshenSubconsciousEchoAnchorActor
 * 
 * 3D world spatial anchor that triggers localized whisper motifs and monologue
 * reflections when Kaelen steps into its proximity.
 */
UCLASS()
class ASHENOATH_API AAshenSubconsciousEchoAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSubconsciousEchoAnchorActor();

	virtual void BeginPlay() override;

	/** Triggers echo playback */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Echo")
	void TriggerSubconsciousEcho();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Echo")
	bool HasFired() const { return bEchoTriggered; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* TriggerPerimeter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* WhisperSpatialAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Echo")
	FString AssociatedMemoryEchoId = TEXT("mem_echo_001");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Echo")
	EVoiceChannel TargetChannel = EVoiceChannel::ShadowSelf;

private:
	bool bEchoTriggered = false;
};
