// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenInteractableActor.h"
#include "AshenDoorActor.generated.h"

class USceneComponent;

/**
 * AAshenDoorActor
 * Interactable door that slides/rotates open. Checks inventory for keys if locked.
 */
UCLASS()
class ASHENOATH_API AAshenDoorActor : public AAshenInteractableActor
{
	GENERATED_BODY()

public:
	AAshenDoorActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(APawn* Player) override;

	/** Toggle the door open or closed smoothly */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Door")
	void ToggleDoor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* DoorPivot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	bool bIsLocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	FName RequiredKeyName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door Settings")
	float OpenAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door Settings")
	float TransitionDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door Settings")
	class USoundBase* DoorCreakSound;

private:
	void UpdatePrompt();

private:
	bool bIsOpen;
	float TargetAngle;
	float CurrentAngle;
};
