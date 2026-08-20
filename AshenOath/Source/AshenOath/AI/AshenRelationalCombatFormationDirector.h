// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenRelationalCombatFormationDirector.generated.h"

/**
 * UAshenRelationalCombatFormationDirector
 * AI Director component orchestrating 3-character relational combat tactical formations and line-of-sight positioning.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalCombatFormationDirector : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRelationalCombatFormationDirector();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	bool bRelationalFormationActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool SynchronizeRelationalFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina);
};
