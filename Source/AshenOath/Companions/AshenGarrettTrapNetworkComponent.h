// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettTrapNetworkComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTrapCascadeTriggered, int32, TrapsDetonatedCount);

/**
 * UAshenGarrettTrapNetworkComponent
 * Component linking deployed traps into synchronized detonation grids.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTrapNetworkComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettTrapNetworkComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnTrapCascadeTriggered OnTrapCascadeTriggered;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	int32 LinkedTrapCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	int32 MaxActiveTrapSlots = 4;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	TArray<FName> ActiveTrapIDs;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void RegisterTrapToNetwork();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool RegisterTrap(FName TrapID, FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool DeregisterTrap(FName TrapID);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Combat")
	int32 GetActiveTrapCount() const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	int32 TriggerNetworkCascade();
};
