// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicAnvilWorldActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenRunicAnvilWorldActor
 * 
 * Physicalized forge anvil actor placed at campfire sites allowing runic socketing.
 */
UCLASS()
class ASHENOATH_API AAshenRunicAnvilWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenRunicAnvilWorldActor();

	virtual void BeginPlay() override;

	/** Triggers the physical forge hammer strike effect */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Forge")
	void TriggerForgeStrike();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Forge")
	bool IsAnvilActive() const { return bAnvilActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AnvilMesh;

private:
	bool bAnvilActive = false;
};
