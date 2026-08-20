// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionRelationalPincerDirector.generated.h"

/**
 * UAshenCompanionRelationalPincerDirector
 * AI Director component orchestrating 3-character companion relational pincer tactical formations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionRelationalPincerDirector : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionRelationalPincerDirector();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	bool bRelationalPincerActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool SynchronizeRelationalPincerFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina);
};
