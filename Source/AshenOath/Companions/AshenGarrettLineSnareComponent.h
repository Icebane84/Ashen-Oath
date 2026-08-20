// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettLineSnareComponent.generated.h"

/**
 * UAshenGarrettLineSnareComponent
 * Component managing Garrett's alchemical line hook, target vault, and volatile oil coat for The Sentinel's Eclipse.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettLineSnareComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettLineSnareComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Garrett Snare")
	bool bTargetNeckExposed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Garrett Snare")
	int32 BonusTacticalSuppliesOnExecution = 3;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Garrett Snare")
	bool ExecuteLineSnareVault(AActor* TargetActor);
};
