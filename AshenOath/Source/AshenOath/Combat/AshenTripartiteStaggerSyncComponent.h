// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenTripartiteStaggerSyncComponent.generated.h"

/**
 * UAshenTripartiteStaggerSyncComponent
 * Coordinates trio positioning and simultaneous ability activation when a boss enters the staggered state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteStaggerSyncComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTripartiteStaggerSyncComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	bool bIsTrioConverged = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	bool ConvergeTrioOnTarget(AActor* BossActor);
};
