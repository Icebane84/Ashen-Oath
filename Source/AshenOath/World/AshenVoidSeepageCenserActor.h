// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenVoidSeepageCenserActor.generated.h"

/**
 * AAshenVoidSeepageCenserActor
 * World prop distilling ambient shadow seepage into volatile gloomwood essence.
 */
UCLASS()
class ASHENOATH_API AAshenVoidSeepageCenserActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenVoidSeepageCenserActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Censer")
	bool bIsCenserActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Censer")
	int32 DistillSeepageReagents(AActor* InstigatingPlayer);
};
