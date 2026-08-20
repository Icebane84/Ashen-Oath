// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonDoorLockComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDoorUnlockedSignature, FName, KeyID);

/**
 * UAshenDungeonDoorLockComponent
 *
 * Manages dungeon door lock state, required key checking, and unlock events.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonDoorLockComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonDoorLockComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|DoorLock")
	bool TryUnlockWithKey(FName PlayerKeyID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|DoorLock")
	bool IsLocked() const { return bIsLocked; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|DoorLock")
	FName RequiredKeyID = FName("Key_SanctuaryGate");

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DoorLock|Events")
	FOnDoorUnlockedSignature OnDoorUnlocked;

private:
	bool bIsLocked = true;
};
