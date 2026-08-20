// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "AshenReflectiveCampfireNexusActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UAudioComponent;

/**
 * AAshenReflectiveCampfireNexusActor
 * 
 * 3D world campfire entity triggering full slow-loop reflection passes:
 * - Triggers ESalienceTriggerClass::CampfireReflection
 * - Compiles multi-author journal entries
 * - Dispenses warm ambient audio
 */
UCLASS()
class ASHENOATH_API AAshenReflectiveCampfireNexusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenReflectiveCampfireNexusActor();

	virtual void BeginPlay() override;

	/** Triggers campfire reflection pass */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Campfire")
	bool InitiateReflectionPass();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Campfire")
	bool IsPassActive() const { return bReflectionInFlight; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* ReflectionPerimeter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* CampfireMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* HearthfireAudio;

private:
	bool bReflectionInFlight = false;
};
