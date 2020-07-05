// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EsferaFlamejante.generated.h"

UCLASS()
class GESTUDO_API AEsferaFlamejante : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEsferaFlamejante();

private:
	//Declaração de um ponteiro que receberá o endereço de um UStaticMeshComponente
	UPROPERTY(EditAnywhere, Category = "Components") UStaticMeshComponent* EsferaVisivel;
	//Declaração de um ponteiro que receberá o endereço de um USPhereComponente, o class serve para declarar o que sérá antes e sua utilização (foward declaration )
	UPROPERTY(EditAnywhere, Category = "Components") class USphereComponent* EsferaDeColisao;
	//Declaração de um ponteiro para um componente de sistema de Particula
	UPROPERTY(EditAnywhere, Category = "Components") class UParticleSystemComponent* ParticulaDeFogo;


protected:

	//EditAnywhere 
	// A Variavél estipulada ou moficada no: Editor da Unreal e Editor da Blueprint, MAS não fica disponível no Event Graph da BluePrint

	//EditDefaultOnly
	// Pode-se Definir um valor padrão para a variável apenas na janela da Blueprint ANTES da execução do jogo. ( não fica acessível dentro do editor da Unreal e nem no Event)

	//VisibleAnywhere
	// Variável visível na janela de Detalhes do editor e Na janela de detalhes da Blueprint mas não poderá ser editada.

	//VisibleDefaultsOnlye
	// Variável visível na janela de propriedades do editor e na janela de detalhes da Blueprint mas não poderá ser editada.

	//BluePrintReadWrite
	// Permite que a variável seja lida ou modificada apenas de dentro do Event Graph da BluePrint(Get e Set) (Não disponivel no editor da Unreal e nem no editor da Blueprint)

	//BluePrintReadWrite
	// Permite que a variável seja lida ou modificada apenas de dentro do Event Graph da BluePrint(Get e Set) (Não disponivel no editor da Unreal e nem no editor da Blueprint) 

	//BluePrintReadOnly
	// Permite que a variável seja lida ( get ) apenas de dentro do Event Graph da BluePrint(Get e Set) (Não disponivel no editor da Unreal e nem no editor da Blueprint) 

	//Category = ""
	// Permite você agrupar variáveis em uma única seção dentro do editor da Unreal eou dentro da Blueprint. Quando usário procurar editar esta variável no editor ou na blueprint, aparece sobre o titulo "Nome"

	// Você pode juntar EditAnywhere, BlueprintReadWrite e EditAnywhere, BlueprintReadOnly

	UPROPERTY(EditAnywhere, Category = "Variaveis") bool VariavelEditAnywhere;
	UPROPERTY(VisibleAnywhere, Category = "Variaveis") float VariavelVisibleAnywhere;
	UPROPERTY(EditDefaultsOnly, Category = "Variaveis") float  VariavelEditDefaultsOnly;
	UPROPERTY(VisibleDefaultsOnly, Category = "Variaveis") float VariavelVisibleDefaultsOnly;
	UPROPERTY(BlueprintReadWrite, Category = "Variaveis") FVector VariavelBlueprintReadWrite = FVector(0.f,0.f,-180.f);
	UPROPERTY(BlueprintReadOnly, Category = "Variaveis") FString VariavelBlueprintReadOnly = "Texto Blueprint";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variaveis")  FString VariavelEditAnywhereBlueprintReadWrite = "Texto Editavel";
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variaveis")  FString VariavelEditAnywhereBlueprintReadOnly = "Outro Texto Blueprint";

	//Macro UFUNCTION define funções e pode receber parâmetros

	UFUNCTION() void IniciouSobreposicao(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION() void TerminouSobreposicao(AActor* OverlappedActor, AActor* OtherActor);

	//foward declaration: precisamos de class para indicar que apesar da classe não estár ainda presente, ela será posteriormente anexada ao projeto no .cpp fazendo um include.
	UPROPERTY(EditAnywhere, Category="Texto") class UTextRenderComponent* TextoDeExibicao;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
