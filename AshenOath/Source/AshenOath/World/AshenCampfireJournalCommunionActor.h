// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenCampfireJournalCommunionActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UAudioComponent;

/**
 * AAshenCampfireJournalCommunionActor
 * 
 * 3D world interaction entity where Kaelen opens the living journal at camp:
 * - Triggers campfire marginalia evaluation pass
 * - Plays immersive quill/charcoal audio cues
 */
UCLASS()
class ASHENOATH_API AAshenCampfireJournalCommunionActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCampfireJournalCommunionActor();

	virtual void BeginPlay() override;

	/** Begins journal communion reflection */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Campfire")
	bool OpenJournalCommunion();

	/** Closes journal communion */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Campfire")
	void CloseJournalCommunion();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Campfire")
	bool IsCommuning() const { return bIsCommunionOpen; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* InteractionPerimeter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* JournalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* AmbientCampfireAudio;

private:
	bool bIsCommunionOpen = false;
};
