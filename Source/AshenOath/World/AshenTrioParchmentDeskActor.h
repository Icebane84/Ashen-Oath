// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenTrioParchmentDeskActor.generated.h"

/**
 * AAshenTrioParchmentDeskActor
 * Interactive campfire field desk where the trio reviews authored journal entries, sketches, and tactical notes.
 */
UCLASS()
class ASHENOATH_API AAshenTrioParchmentDeskActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenTrioParchmentDeskActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Camp")
	bool bIsDeskOpen = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Camp")
	void OpenParchmentDesk(AActor* InstigatingPlayer);
};
