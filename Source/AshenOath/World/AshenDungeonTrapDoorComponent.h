// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonTrapDoorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTrapDoorTriggeredSignature, AActor*, TriggeringActor);

/**
 * UAshenDungeonTrapDoorComponent
 *
 * Dungeon trapdoor / pitfall component.
 * Triggers opening sequence when an actor steps onto pressure plate area.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonTrapDoorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonTrapDoorComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|TrapDoor")
	void TriggerTrap(AActor* TriggeringActor);

	UFUNCTION(BlueprintPure, Category = "AshenOath|TrapDoor")
	bool IsTrapTriggered() const { return bIsTriggered; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|TrapDoor")
	float OpenDelay = 0.5f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TrapDoor|Events")
	FOnTrapDoorTriggeredSignature OnTrapDoorTriggered;

private:
	bool bIsTriggered = false;
	FTimerHandle OpenTimerHandle;

	void ExecuteTrapOpen(AActor* TriggeringActor);
};
