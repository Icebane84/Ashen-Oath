// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenRunicMemoryMonolithActor.generated.h"

/**
 * AAshenRunicMemoryMonolithActor
 * Ancient runic stone monument in the world unsealing encrypted lorekeeper entries upon proximity communion.
 */
UCLASS()
class ASHENOATH_API AAshenRunicMemoryMonolithActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenRunicMemoryMonolithActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Codex")
	FName UnlockedCodexID = NAME_None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Codex")
	bool bIsDeciphered = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	bool DecipherMonolith(AActor* InstigatingPlayer);
};
