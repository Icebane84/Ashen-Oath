// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenInteractableActor.h"
#include "AshenChestActor.generated.h"

class UStaticMeshComponent;
class UAshenOath_LootComponent;

/**
 * AAshenChestActor
 * Interactable chest that opens its lid smoothly and triggers dynamic item drops.
 */
UCLASS()
class ASHENOATH_API AAshenChestActor : public AAshenInteractableActor
{
	GENERATED_BODY()

public:
	AAshenChestActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(APawn* Player) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* LidMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAshenOath_LootComponent* LootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chest Settings")
	float OpenAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chest Settings")
	float OpenDuration;

private:
	bool bIsOpen;
	float TargetAngle;
	float CurrentAngle;
};
