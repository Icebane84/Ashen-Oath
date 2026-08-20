// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenInteractableActor.h"
#include "AshenLeverActor.generated.h"

class UStaticMeshComponent;
class AAshenDoorActor;

/**
 * AAshenLeverActor
 * Interactable lever that rotates its handle and toggles a target door open/closed.
 */
UCLASS()
class ASHENOATH_API AAshenLeverActor : public AAshenInteractableActor
{
	GENERATED_BODY()

public:
	AAshenLeverActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(APawn* Player) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* HandleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lever Settings")
	AAshenDoorActor* TargetDoor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lever Settings")
	float LeverAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lever Settings")
	float TransitionDuration;

private:
	bool bPulled;
	float TargetAngle;
	float CurrentAngle;
};
