// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenTacticalTargetMarkerWorldActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenTacticalTargetMarkerWorldActor
 * 
 * World holographic reticle spawned at marked tactical attack locations.
 */
UCLASS()
class ASHENOATH_API AAshenTacticalTargetMarkerWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenTacticalTargetMarkerWorldActor();

	virtual void BeginPlay() override;

	/** Sets the active command type for visual styling */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Tactics")
	void SetCommandStyle(ETacticalCommandType CommandType);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Tactics")
	bool IsMarkerVisible() const { return bIsVisible; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ReticleMesh;

private:
	bool bIsVisible = false;
};
